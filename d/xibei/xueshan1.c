#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","��ѩɽ");
    set("long",@LONG
��ѩɽɽ��ͦ�Σ����г���֮�ƣ�ɽ�ϵ�������ʮ�ɺ�Ļ�ѩ�ͱ������м�
ż��¶���������ɽ�ң�������ҫ�£���Ŀҫ�ۣ������������۾���ɽ�Ϻ�����
��������̹ǣ���֮�����䣬��ʱͻ����ѩ�����������Ʋ������±���⻬��
�ʣ�һ������ͻ�ˤ��������û�а��������
    ������ɽ��һƬ�����ĸ�ԭ�ݵ�����󣬺��������岼��
LONG);
    set("exits",([
        "eastdown"    : __DIR__"xingxiu_hai",
    ]));
    set("outdoors","xibei");
    setup();
}
void init()
{
        object ob;
        ob = this_player();
        if( (int)ob->query("max_neili") > 400) return;
        
        tell_object(ob,BLU "�����һ�󺮷��ƺ�ֱ��������Ĺ�����..........\n\n" NOR);
        ob->start_busy(3);
        //ob->apply_condition("ganmao",15);
        return;
}


