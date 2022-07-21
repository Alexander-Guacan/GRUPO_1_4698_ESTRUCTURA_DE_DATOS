#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

class ProgressBar {
    private:
        const short DEFAUL_VELOCITY{3};
        bool useThread{false};
        short horizontalStartPosition{};
        short width{};
        short verticalPosition{};
        short velocity{};

        void printProgressBarIcon(short x);
        void printProgressBarWithoutLoad();
        void loadProgressBar();

    public:
        /**
         * @brief Construct a new Progress Bar object
         * 
         * @param xStartPosition 0 - width of console
         * @param widthOfProgressBar 
         * @param velocityOfRender 1 - 5
         */
        ProgressBar(short xStartPosition, short widthOfProgressBar, short velocityOfRender);

        /**
         * @brief Set the vertical position
         * 
         * @param y 0 - hight of console
         */
        void setVerticalPosition(short y);

        /**
         * @brief Set the Limits object
         * 
         * @param xStartPosition 0 - width of console
         * @param newWidth width of progress bar
         */
        void setLimits(short xStartPosition, short newWidth);

        /**
         * @brief Set the Velocity object
         * 
         * @param newVelocity 1 - 5
         */
        void setVelocity(short newVelocity);

        /**
         * @brief Start the printing of progress bar
         * 
         */
        void print();

        /**
         * @brief Start the printing of progress bar, use this function when other process use the output stream of console at the same time
         * 
         */
        void printUsingThread();
};

#endif