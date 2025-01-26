import React from 'react';
import { useSelector } from 'react-redux';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faArrowTrendUp, faCloudRain, faCompass, faDroplet, faSun, faWind } from '@fortawesome/free-solid-svg-icons';

const WeatherCard = ({ icon, title, value, color }) => {
    return (
      <div className={`flex border-2 border-none w-full items-center text-white md:w-1/2 lg:w-1/4 xl:w-1/4`}>
        <FontAwesomeIcon className={`${color}`} icon={icon} />
        <div className='pl-3'>
          <p className='text-[#7686A3] whitespace-nowrap'>{title}</p>
          <p className='whitespace-nowrap'>{value}</p>
        </div>
      </div>
    );
  };

export default function SecondaryDetails() {
  const weatherData = useSelector((state) => state.weather?.data);

  if (!weatherData) {
    return <p> </p>;
  }
  if (weatherData?.error?.code) {
    return <p> </p>;
  }

  return (
    <div className='border-2 border-none pt-6 mr-24 pl-16 grid grid-cols-1  md:grid-cols-2 lg:grid-cols-4 xl:grid-cols-4 w-full'>
      <WeatherCard 
        icon={faCloudRain} 
        title="Chance of Rain" 
        value={`${weatherData.forecast.forecastday[0].day.daily_chance_of_rain}%`} 
        color="text-blue-600" 
      />
      <WeatherCard 
        icon={faWind} 
        title="Wind" 
        value={`${weatherData.current.wind_kph} Km/h`} 
        color="text-white" 
      />
      <WeatherCard 
        icon={faSun} 
        title="Sunrise" 
        value={weatherData.forecast.forecastday[0].astro.sunrise} 
        color="text-orange-600" 
      />
      <WeatherCard 
        icon={faSun} 
        title="Sunset" 
        value={weatherData.forecast.forecastday[0].astro.sunset} 
        color="text-red-600" 
      />
      <WeatherCard 
        icon={faSun} 
        title="UV Index" 
        value={weatherData.current.uv} 
        color="text-yellow-400" 
      />
      <WeatherCard 
        icon={faArrowTrendUp} 
        title="Pressure" 
        value={`${weatherData.current.pressure_mb} hPa`} 
        color="text-pink-400" 
      />
      <WeatherCard 
        icon={faDroplet} 
        title="Humidity" 
        value={`${weatherData.current.humidity}%`} 
        color="text-blue-600" 
      />
      <WeatherCard 
        icon={faCompass} 
        title="Wind Direction" 
        value={weatherData.current.wind_dir} 
        color="text-gray-400" 
      />
    </div>
  );
}