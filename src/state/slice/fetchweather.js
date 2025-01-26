import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";

export const fetchWeather = createAsyncThunk("fetchWeather", async (city) => {
    console.log(city);
    const response = await fetch(`http://api.weatherapi.com/v1/forecast.json?key=b44b5c71823e4440a1664611241408&q=${city}&days=7&aqi=no&alerts=no`);
    const data = await response.json();
    return data;
})

const weatherSlice = createSlice({
    name: 'Weather',
    initialState: {
        isLoading: false,
        data: null,
        error: false,
    },
    extraReducers: (build) => {
        build.addCase(fetchWeather.pending, (state, action) => {
            state.isLoading = true;
            state.error = false;
        });
        build.addCase(fetchWeather.fulfilled, (state, action) => {
            state.isLoading = false;
            state.data = action.payload;
            state.error = false;
        });
        build.addCase(fetchWeather.rejected, (state, action) => {
            state.isLoading = false;
            state.error = true;
            console.log("ERROR: ", action.payload);
        });
    }
});

export default weatherSlice.reducer;
