//��˽�
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIY"��˽�"NOR, ({"phoenix sword","sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�ഫ��һ�Է�˻��ɵı�����\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$Nһ����Х����˽�����Ȱ���������\n"NOR);
                set("unwield_msg",HIW "$N���з�˽�ͻȻ����һ�ź���,��ʧ�ڿ�����.\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(920);
        setup();
}
