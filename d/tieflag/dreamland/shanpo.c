 // street2.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
string rider();
void create()
{
  set("short","ɽ��");
  set("long",@LONG
����·��ǳ�¥���Ͻ���һ������ɽ��Զ���ĳ�¥������������֮�С�����
���ź�����ɽ�¶����Ƿ���������ǰ��ƽԭ����ǧ����������ɱ�У��̳��ܴ�
�㿴�����Զ����ս����ֻ�ܿ���һ�Ӷ����������������ڵ�ɽ�������濪�Ρ� 
LONG
  );
        set("exits",([
                "up" : __DIR__"shanding",
                "south" : "/d/yanmen/camp8",

    

    
    ]));
        set("item_desc", ([
                "���" : (: rider :),
                "qibing" : (: rider :),
                "rider" : (: rider :),
        ]));
    set("valid_startroom",1);
    set("outdoors", "dreamland");
        set("no_fight", 1);
        set("no_magic", 1);
        setup(); 
} 
string rider(){
        object me;
        me = this_player();
        tell_object(me, "���������Ĵ���γ������ һ����г������Ĵ���ӭ����չ���м䶷\n"); 
        tell_object(me, "���"HIR"��"NOR"��������ɽ��\n"); 
        return "";
}       
