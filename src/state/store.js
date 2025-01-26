import { configureStore } from "@reduxjs/toolkit";
import weatherSlice from "./slice/fetchweather"

export const store = configureStore({
    reducer: {
        weather: weatherSlice,
    },
});