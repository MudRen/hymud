#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(CYN "������" NOR, ({ "tulong blade" , "blade" ,"dao", "tulong" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "����Ǻų���������������������ĳ������ĵ���������һ�ٶ��֮�ء�\n�ഫ���в��п����Ĵ����ܡ�\n" NOR);
                set("value", 5000);
                set("no_sell", "����������������\n");
                set("rigidity",8000);   
                set("material", "steel");
                set("wield_msg", HIY "$Nһ����Ц���ӱ������Ǳ��ųơ�"NOR+HIR"��������"NOR+HIY"�������������߸߾���\n" NOR);
                set("unwield_msg", HIY "$N����һЦ��������������ر���\n"NOR);
        }
        init_blade(500);
        setup();
}
