/*
1. Ny Entity opprettes
2. RenderSystem vil vite om Entity har de to komponents som den trenger (Transform & Render)
3. Hvis den nye Entity inneholder TransformComponent OG RenderComponent:
    RenderSystem vil da lagre referanse til disse to KOMPONENTENE i sin liste over komponenter den styrer
*/