#ifndef TREVOR_TIMER_H
#define TREVOR_TIMER_H
#include <chrono>
#include <ostream>

/*
    Represents a timer with a start and end time
    Start time is recorded at initialization, but can be set with start()
*/

namespace TimerUnits{
    enum class Unit{
        Nano,
        Micro,
        Milli,
        Sec
    };
};

template <typename Rep = double, class Clock = std::chrono::steady_clock>
class Timer{
    public:
        using TimePoint = std::chrono::time_point<Clock>;
        using Duration = std::chrono::duration<Rep, std::nano>;
        using Unit = TimerUnits::Unit;
        
        //Unit to default convert to
        Timer(Unit unit = Unit::Milli) :  _startPoint(now()), 
                            _endPoint(_startPoint),
                            _durationCount(0),
                            _duration(Duration::zero()), 
                            _UNIT(unit), 
                            _UNIT_LABEL(unitToLabel(unit))
        {}

        //Resets and sets start time to now
        TimePoint start(){
            reset();
            return _startPoint;
        }
        //Sets end time to now and calculates duration
        Rep end(){
            _endPoint = now();
            _calcDuration();
            return _durationCount;
        }

        TimePoint startPoint() const {
            return _startPoint;
        }

        TimePoint endPoint() const {
            return _endPoint;
        }

        Rep duration() const {
            return _durationCount;
        }

        //Converts duration to desired unit
        Rep durationAs(Unit unit) const {
            switch(unit){
                case Unit::Nano:
                    return std::chrono::duration_cast<std::chrono::duration<Rep, std::nano>>(_duration).count();
                case Unit::Micro:
                    return std::chrono::duration_cast<std::chrono::duration<Rep, std::micro>>(_duration).count();
                case Unit::Milli:
                    return std::chrono::duration_cast<std::chrono::duration<Rep, std::milli>>(_duration).count();
                case Unit::Sec:
                default:
                    return std::chrono::duration_cast<std::chrono::duration<Rep, std::ratio<1, 1>>>(_duration).count();
            }
        }

        Unit unit() const {
            return _UNIT;
        }

        //Resets timer
        void reset(){
            _startPoint = now();
            _endPoint = _startPoint;
            _duration = Duration::zero();
            _durationCount = 0;
        }

        //Gets current time using steady_clock
        static TimePoint now(){
            return Clock::now();
        }

        static const char *unitToLabel(Unit unit){
            switch(unit){
                case Unit::Nano:
                    return "ns";
                case Unit::Micro:
                    return "us";
                case Unit::Milli:
                    return "ms";
                case Unit::Sec:
                default:
                    return "s";
            }
        }
    private:
        TimePoint _startPoint, _endPoint;
        Rep _durationCount; //Duration in _UNIT units
        Duration _duration; //std::chrono::duration used to hold actual duration for conversions
        const Unit _UNIT;
        const char *_UNIT_LABEL;

        void _calcDuration(){
            _duration = _endPoint - _startPoint;
            _durationCount = durationAs(_UNIT);
        }
    template <typename R, class C>
    friend std::ostream &operator<<(std::ostream&, const Timer<R, C>&);
};

template <typename Rep, class Clock>
std::ostream &operator<<(std::ostream &out, const Timer<Rep, Clock> &timer){
    out << timer._durationCount << ' ' << timer._UNIT_LABEL;
    return out;
}

#endif //TREVOR_TIMER_H