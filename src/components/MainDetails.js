import React from 'react';
import { useSelector } from 'react-redux';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faArrowUp, faArrowDown, faLocationDot, faGauge } from '@fortawesome/free-solid-svg-icons';

const CurrentWeather = ({ weatherData }) => {
    return (
        <div className="flex flex-col text-center sm:text-start sm:pt-6 sm:pl-6">
            <p className="text-7xl text-white">{weatherData.current.temp_c}&deg;</p>
            <p className="text-md text-nowrap text-[#7686A3] pt-3">{weatherData.current.condition.text}</p>
            <p className="text-md text-nowrap text-red-400">Feels like {weatherData.current.feelslike_c}&deg;</p>
        </div>
    );
};

const Forecast = ({ weatherData }) => {
    return (
        <div className="grid w-full sm:justify-end pt-12 border-2 border-none">
            <div className="flex space-x-5 pl-4 sm:pl-0 sm:space-x-14 sm:pr-4">
                <div className="flex justify-center items-center">
                    <div className="w-8 h-8 bg-[#1C489C] rounded-full flex justify-center items-center">
                        <FontAwesomeIcon className="rounded-full bg-[#1C489C] border-none text-white w-3 h-3" icon={faArrowUp} />
                    </div>
                    <div>
                        <p className="text-white text-xs">Max</p>
                        <p className="text-white text-2xl">{weatherData.forecast.forecastday[0].day.maxtemp_c}&deg;</p>
                    </div>
                </div>
                <div className="flex justify-center items-center">
                    <div className="w-8 h-8 bg-[#1C489C] rounded-full flex justify-center items-center">
                        <FontAwesomeIcon className="rounded-full bg-[#1C489C] border-none text-white w-3 h-3" icon={faGauge} />
                    </div>
                    <div>
                        <p className="text-white text-xs">Avg</p>
                        <p className="text-white text-2xl">{weatherData.forecast.forecastday[0].day.avgtemp_c}&deg;</p>
                    </div>
                </div>
                <div className="flex justify-center items-center pr-3">
                    <div className="w-8 h-8 bg-[#1C489C] rounded-full flex justify-center items-center">
                        <FontAwesomeIcon className="rounded-full bg-[#1C489C] border-none text-white w-3 h-3" icon={faArrowDown} />
                    </div>
                    <div>
                        <p className="text-white text-xs">Min</p>
                        <p className="text-white text-2xl">{weatherData.forecast.forecastday[0].day.mintemp_c}&deg;</p>
                    </div>
                </div>
            </div>
            <div className="flex justify-center sm:justify-start items-center">
                <FontAwesomeIcon className="text-md text-[#7686A3]" icon={faLocationDot} />
                <p className="text-[#7686A3] text-nowrap text-md pl-1">{weatherData.location.name}, {weatherData.location.region}, {weatherData.location.country}</p>
            </div>
        </div>
    );
};


const MainDetails = () => {
    const state = useSelector((state) => state);
    const weatherData = state.weather?.data;

    if (!weatherData && state.weather.isLoading) {
        return <div></div>;
    }

    if (!weatherData) {
        return <div className="flex justify-center items-center text-white animate-pulse">Search a City</div>;
    }
    if (weatherData?.error?.code) {
        return <p className="flex justify-center items-center text-white">{weatherData.error.message}</p>;
    }

    return (
        <div className="border-2 border-none sm:mx-14">
            <div className="flex flex-col mx-6 sm:mx-0 items-center sm:flex-row sm:pl-6 border-2 border-none">
                <img className="size-36" src={weatherData.current.condition.icon} alt="Nigga" />
                <CurrentWeather weatherData={weatherData} />
                <Forecast weatherData={weatherData} />
            </div>
        </div>
    );
};

export default MainDetails;