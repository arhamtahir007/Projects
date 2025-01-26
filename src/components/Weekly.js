import React from 'react';
import { useSelector } from 'react-redux';

export default function Weekly() {
  const weatherData = useSelector((state) => state.weather?.data);

  if (!weatherData) {
    return <div className='flex justify-center items-center text-white'> </div>
  }
  if (weatherData?.error?.code) {
    return <p className='flex justify-center items-center text-white'> </p>
  }

  const formatDate = (dateString) => {
    const options = { month: 'long', day: 'numeric' }
    const date = new Date(dateString)
    const formattedDate = new Intl.DateTimeFormat('en-US', options).format(date)
    const monthName = formattedDate.split(' ')[0]
    if (monthName.length > 4) {
      return `${formattedDate.split(' ')[1]} ${monthName.substring(0, 3)}`
    }
    return formattedDate
  }

  const formatDay = (dateString) => {
    const options = { weekday: 'long' }
    const date = new Date(dateString)
    const day = new Intl.DateTimeFormat('en-US', options).format(date)
    return day.substring(0, 3)
  }

  const ForecastCard = ({ date, icon, minTemp, maxTemp }) => {
    return (
      <div className='flex items-center bg-[#1C489C] rounded-lg w-10/12 mx-2 mt-1 mb-1'>
        <img src={icon} alt='Weather Icon' />
        <div className='flex flex-col w-full ml-4'>
          <p className='text-white'>{formatDay(date)}</p>
          <p className='text-[#7686A3]'>{formatDate(date)}</p>
          <div className='grid grid-cols-2 grid-rows-2'>
            <p className='font-bold text-white text-xl'>{minTemp}&deg;</p>
            <p className='font-bold text-white text-xl'>{maxTemp}&deg;</p>
            <p className='text-white text-xs'>Min</p>
            <p className='text-white text-xs'>Max</p>
          </div>
        </div>
      </div>
    )
  }

  return (
    <>
      <h2 className='border-2 border-none mx-3 pl-2 sm:pl-12 text-white font-bold pb-0 pt-2'>This Week</h2>
      <div className='grid grid-cols-1 grid-rows-2 mx-3 pl-9 border-2 border-none md:grid-cols-2 lg:grid-cols-3'>
        {weatherData.forecast.forecastday.slice(1).map((forecast, index) => (
          <ForecastCard
            key={index}
            date={forecast.date}
            icon={forecast.day.condition.icon}
            minTemp={forecast.day.mintemp_c}
            maxTemp={forecast.day.maxtemp_c}
          />
        ))}
      </div>
    </>
  )
}