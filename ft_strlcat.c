size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t dst_len;

    dst_len = ft_strlen(dst);
    if (size <= dst_len)
        return (size + ft_strlen(src));
    i = dst_len;
    j = 0;
    while (src[j] && i < size - 1)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
    return (dst_len + ft_strlen(src));
}
