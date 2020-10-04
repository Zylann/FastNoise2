#include "FastSIMD/InlInclude.h"

#include "Perlin.h"
#include "Utils.inl"

template<typename FS>
class FS_T<FastNoise::Perlin, FS> : public virtual FastNoise::Perlin, public FS_T<FastNoise::Generator, FS>
{
    FASTSIMD_DECLARE_FS_TYPES;

    float32v FS_VECTORCALL Gen( int32v seed, float32v x, float32v y ) const final
    {
        float32v xs = FS_Floor_f32( x );
        float32v ys = FS_Floor_f32( y );

        int32v x0 = FS_Convertf32_i32( xs ) * int32v( Primes::X );
        int32v y0 = FS_Convertf32_i32( ys ) * int32v( Primes::Y );
        int32v x1 = x0 + int32v( Primes::X );
        int32v y1 = y0 + int32v( Primes::Y );

        float32v xf0 = xs = x - xs;
        float32v yf0 = ys = y - ys;
        float32v xf1 = xf0 - float32v( 1 );
        float32v yf1 = yf0 - float32v( 1 );

        xs = Utils::InterpQuintic( xs );
        ys = Utils::InterpQuintic( ys );

        return float32v( 0.579106986522674560546875f ) * Utils::Lerp(
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0 ), xf0, yf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0 ), xf1, yf0 ), xs ),
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1 ), xf0, yf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1 ), xf1, yf1 ), xs ), ys );
    }

    float32v FS_VECTORCALL Gen( int32v seed, float32v x, float32v y, float32v z ) const final
    {
        float32v xs = FS_Floor_f32( x );
        float32v ys = FS_Floor_f32( y );
        float32v zs = FS_Floor_f32( z );

        int32v x0 = FS_Convertf32_i32( xs ) * int32v( Primes::X );
        int32v y0 = FS_Convertf32_i32( ys ) * int32v( Primes::Y );
        int32v z0 = FS_Convertf32_i32( zs ) * int32v( Primes::Z );
        int32v x1 = x0 + int32v( Primes::X );
        int32v y1 = y0 + int32v( Primes::Y );
        int32v z1 = z0 + int32v( Primes::Z );

        float32v xf0 = xs = x - xs;
        float32v yf0 = ys = y - ys;
        float32v zf0 = zs = z - zs;
        float32v xf1 = xf0 - float32v( 1 );
        float32v yf1 = yf0 - float32v( 1 );
        float32v zf1 = zf0 - float32v( 1 );

        xs = Utils::InterpQuintic( xs );
        ys = Utils::InterpQuintic( ys );
        zs = Utils::InterpQuintic( zs );

        return float32v( 0.964921414852142333984375f ) * Utils::Lerp( Utils::Lerp(
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0, z0 ), xf0, yf0, zf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0, z0 ), xf1, yf0, zf0 ), xs ),
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1, z0 ), xf0, yf1, zf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1, z0 ), xf1, yf1, zf0 ), xs ), ys ),
            Utils::Lerp( 
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0, z1 ), xf0, yf0, zf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0, z1 ), xf1, yf0, zf1 ), xs ),    
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1, z1 ), xf0, yf1, zf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1, z1 ), xf1, yf1, zf1 ), xs ), ys ), zs );
    }

    float32v FS_VECTORCALL Gen( int32v seed, float32v x, float32v y, float32v z, float32v w ) const final
    {
        float32v xs = FS_Floor_f32( x );
        float32v ys = FS_Floor_f32( y );
        float32v zs = FS_Floor_f32( z );
        float32v ws = FS_Floor_f32( w );

        int32v x0 = FS_Convertf32_i32( xs ) * int32v( Primes::X );
        int32v y0 = FS_Convertf32_i32( ys ) * int32v( Primes::Y );
        int32v z0 = FS_Convertf32_i32( zs ) * int32v( Primes::Z );
        int32v w0 = FS_Convertf32_i32( ws ) * int32v( Primes::W );
        int32v x1 = x0 + int32v( Primes::X );
        int32v y1 = y0 + int32v( Primes::Y );
        int32v z1 = z0 + int32v( Primes::Z );
        int32v w1 = w0 + int32v( Primes::W );

        float32v xf0 = xs = x - xs;
        float32v yf0 = ys = y - ys;
        float32v zf0 = zs = z - zs;
        float32v wf0 = ws = w - ws;
        float32v xf1 = xf0 - float32v( 1 );
        float32v yf1 = yf0 - float32v( 1 );
        float32v zf1 = zf0 - float32v( 1 );
        float32v wf1 = wf0 - float32v( 1 );

        xs = Utils::InterpQuintic( xs );
        ys = Utils::InterpQuintic( ys );
        zs = Utils::InterpQuintic( zs );
        ws = Utils::InterpQuintic( ws );

        return float32v( 0.964921414852142333984375f ) * Utils::Lerp( Utils::Lerp( Utils::Lerp(
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0, z0, w0 ), xf0, yf0, zf0, wf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0, z0, w0 ), xf1, yf0, zf0, wf0 ), xs ),
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1, z0, w0 ), xf0, yf1, zf0, wf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1, z0, w0 ), xf1, yf1, zf0, wf0 ), xs ), ys ),
            Utils::Lerp(                                                                                                                                                     
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0, z1, w0 ), xf0, yf0, zf1, wf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0, z1, w0 ), xf1, yf0, zf1, wf0 ), xs ),    
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1, z1, w0 ), xf0, yf1, zf1, wf0 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1, z1, w0 ), xf1, yf1, zf1, wf0 ), xs ), ys ), zs ),
            Utils::Lerp( Utils::Lerp(
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0, z0, w1 ), xf0, yf0, zf0, wf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0, z0, w1 ), xf1, yf0, zf0, wf1 ), xs ),
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1, z0, w1 ), xf0, yf1, zf0, wf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1, z0, w1 ), xf1, yf1, zf0, wf1 ), xs ), ys ),
            Utils::Lerp(                                                                                                                                                     
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y0, z1, w1 ), xf0, yf0, zf1, wf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y0, z1, w1 ), xf1, yf0, zf1, wf1 ), xs ),    
            Utils::Lerp( Utils::GetGradientDot( Utils::HashPrimes( seed, x0, y1, z1, w1 ), xf0, yf1, zf1, wf1 ), Utils::GetGradientDot( Utils::HashPrimes( seed, x1, y1, z1, w1 ), xf1, yf1, zf1, wf1 ), xs ), ys ), zs ), ws );
    }
};
