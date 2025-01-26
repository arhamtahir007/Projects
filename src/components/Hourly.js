import React from 'react';
import { useSelector } from 'react-redux';

export default function Hourly() {
    const weatherData = useSelector((state) => state.weather?.data);

    if (!weatherData) {
        return <div className='flex justify-center items-center text-white'> </div>;
    }
    if (weatherData?.error?.code) {
        return <p className='flex justify-center items-center text-white'> </p>
    }

    const hours = weatherData.forecast.forecastday[0].hour;
    const nextDayHours = weatherData.forecast.forecastday[1].hour;
    const currentTime = new Date().getHours();
    const startIndex = hours.findIndex((hour) => parseInt(hour.time.split(' ')[1].slice(0, 2)) >= currentTime);

    const remainingHours = hours.slice(startIndex);
    const totalHours = remainingHours.concat(nextDayHours);

    return (
        <>
            <h2 className='border-2 border-none mx-3 pl-2 sm:pl-12 text-white font-bold pb-2 pt-2'>Hourly</h2>
            <div className='overflow-x-auto flex mx-3 pl-9 scrollbar-none'>
                <div className='flex flex-nowrap'>
                    {totalHours.slice(0, 24).map((hour, index) => (
                        <div key={index} className='flex flex-col items-center bg-[#1C489C] rounded-lg w-24 mx-2'>
                            <p className='text-white pt-2'>{formatTime(hour.time)}</p>
                            <img src={hour.condition.icon} />
                            <p className='text-white pb-2'>{hour.temp_c}&deg;</p>
                        </div>
                    ))}
                </div>
            </div>
        </>
    );
}

function formatTime(time) {
    const hour = parseInt(time.split(' ')[1].slice(0, 2));
    const ampm = hour < 12 ? 'AM' : 'PM';
    const formattedHour = hour % 12 || 12;
    return `${formattedHour} ${ampm}`;
}