// ����ī /d/city/chuzhou/npc/obj/gaoli_mo.c
// by lala, 1997-12-14

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( RED"����"HBWHT BLK"ī"NOR, ({"gaoli mo", "mo", }));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
īҲ��࣬����ī���й���ʹ�õģ��������˸����Ժ󣬸����������ر�ĺ�
���ر��й����������ī������Ҳ�͸���ĺá���ͬ����ֽһ����������īҲ
����й�ʿ���ĺ�����
LONG
    );
                set("unit", "��");
                set("value", 10000);
        }
        setup();
}
