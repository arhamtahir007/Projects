import React, { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { fetchWeather } from '../state/slice/fetchweather';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faGear, faSearch } from '@fortawesome/free-solid-svg-icons';
import '../App.css'

export default function ApiCall() {
    const dispatch = useDispatch();
    const state = useSelector((state) => state);
    const [city, setCity] = useState('Islamabad');
    const changeCity = (event) => {
        setCity(event.target.value);
    };


    return (
        <>
            <div className="flex w-11/10 sm:mx-10 border-2 border-none">
                <div className="border-2 w-full mt-3.5 bg-[#1C489C] text-white border-none flex align-middle rounded-full mr-2 ml-4 my-4 pl-2 pr-0 group hover:bg-black hover:text-white">
                    <input
                        className="flex-grow border-none outline-none bg-[#1C489C] group-hover:bg-black group-hover:text-white rounded-full"
                        autoComplete="off"
                        type="text"
                        name="cityInput"
                        placeholder="City Name"
                        onChange={changeCity}
                    />
                    <button
                        className="w-10 h-10 border-none outline-none rounded-full bg-[#1C489C] group-hover:bg-black hover:text-green-600"
                        onClick={() => {
                            dispatch(fetchWeather(city));
                            console.log("State: ", state);

                        }}
                    >
                        <FontAwesomeIcon icon={faSearch} />
                    </button>
                </div>
                <div>
                    <button className="rounded-full border-2 bg-[#1C489C] text-white border-none mr-4 h-10 mt-3.5 w-10 content-center align-middle hover:text-green-600 hover:bg-black active:animate-spin">
                        <FontAwesomeIcon icon={faGear} />
                    </button>
                </div>
            </div>
            {state.weather.isLoading ? <div className="spinner"></div> : <></>}
        </>
    );
}