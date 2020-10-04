#include "FastSIMD/InlInclude.h"

#include "Value.h"
#include "Utils.inl"

template<typename FS>
class FS_T<FastNoise::Value, FS> : public virtual FastNoise::Value, public FS_T<FastNoise::Generator, FS>
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

        xs = Utils::InterpHermite( x - xs );
        ys = Utils::InterpHermite( y - ys );

        return Utils::Lerp(
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0 ), Utils::GetValueCoord( seed, x1, y0 ), xs ),
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1 ), Utils::GetValueCoord( seed, x1, y1 ), xs ), ys );
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

        xs = Utils::InterpHermite( x - xs );
        ys = Utils::InterpHermite( y - ys );
        zs = Utils::InterpHermite( z - zs );

        return Utils::Lerp( Utils::Lerp(
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0, z0 ), Utils::GetValueCoord( seed, x1, y0, z0 ), xs ),
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1, z0 ), Utils::GetValueCoord( seed, x1, y1, z0 ), xs ), ys ),
            Utils::Lerp(                                                                                
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0, z1 ), Utils::GetValueCoord( seed, x1, y0, z1 ), xs ),    
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1, z1 ), Utils::GetValueCoord( seed, x1, y1, z1 ), xs ), ys ), zs );
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

        xs = Utils::InterpHermite( x - xs );
        ys = Utils::InterpHermite( y - ys );
        zs = Utils::InterpHermite( z - zs );
        ws = Utils::InterpHermite( w - ws );

        return Utils::Lerp( Utils::Lerp( Utils::Lerp(
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0, z0, w0 ), Utils::GetValueCoord( seed, x1, y0, z0, w0 ), xs ),
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1, z0, w0 ), Utils::GetValueCoord( seed, x1, y1, z0, w0 ), xs ), ys ),
            Utils::Lerp( 
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0, z1, w0 ), Utils::GetValueCoord( seed, x1, y0, z1, w0 ), xs ),    
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1, z1, w0 ), Utils::GetValueCoord( seed, x1, y1, z1, w0 ), xs ), ys ), zs ),
            Utils::Lerp( Utils::Lerp(
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0, z0, w1 ), Utils::GetValueCoord( seed, x1, y0, z0, w1 ), xs ),
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1, z0, w1 ), Utils::GetValueCoord( seed, x1, y1, z0, w1 ), xs ), ys ),
            Utils::Lerp( 
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y0, z1, w1 ), Utils::GetValueCoord( seed, x1, y0, z1, w1 ), xs ),    
            Utils::Lerp( Utils::GetValueCoord( seed, x0, y1, z1, w1 ), Utils::GetValueCoord( seed, x1, y1, z1, w1 ), xs ), ys ), zs ), ws );
    }
};
