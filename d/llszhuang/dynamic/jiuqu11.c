#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����Ż���");
        set("long",
"�������ߡ���ʮ�����ȣ��໥���������಻����ֱ�������޾���ÿ��\n"
"����ת�䴦����һյ�������ҡ�β����ĻƵơ��ȱߵ�̶ˮ�ڵƹ�����\n"
"�·���ī�̵���⡣\n"
);
        set("no_magic", "1");
        setup();
}
int valid_leave(object me, string dir)
{
     if(random(me->query("kar")) < 15 )
message_vision(GRN"��������һ������...һ��ţëϸ����$N������\n"NOR,me);
     if(random(me->query_skill("dodge") / 100) > 10 ) {
     message_vision(RED"ֻ��$Nһ���Һ���ϸ������ض�����$N�����ϣ�\n"NOR,me);
     me->receive_wound("qi",random(me->query_skill("dodge") / 10));
     }
     else
     message_vision(GRN"$N���ɵĶ��˿�ȥ��\n"NOR,me);
     return ::valid_leave(me, dir);
}

