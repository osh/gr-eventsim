
class load_generator {
    public:
        load_generator(float load);
        void work();
    private:
        float d_load;
        int d_state;
};
