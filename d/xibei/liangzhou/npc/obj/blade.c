//blade.c ��겵�
//Hydra copied from fenglei-dao

#include <weapon.h>
#include <armor.h>
#include <ansi.h>

inherit BLADE;

void create()
{
    set_name( YEL"��겵�"NOR, ({ "yanling dao", "dao", "blade"}) );
    set_weight( 6000 );                     
    set( "long", "һ�����λεĸֵ���������������ģ�һ����֪���Ǻõ���\n" );
    if ( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit", "��" );
        set( "value", 15000 );               
        set( "material", "steel" );         
    }
    init_blade( 40 );                       
    set( "wield_msg", "$N��ৡ���һ�����һ�����λε�$n�������С�\n" );
    set( "unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");

    setup();
}

