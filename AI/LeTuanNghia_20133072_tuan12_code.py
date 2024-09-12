#%%
import gym

if __name__=="__main__":
    env = gym.make("Acrobot-v1")
    #env = gym.make("CubeCrash-v0")
    #env = gym.make("LunarLander-v2")
    obs = env.reset()

    while True:
        action = env.action_space.sample()
        obs, reward, done, info = env.step(action)
        env.render()


        if done:
            env.close()
            break
# %%
