 // Room: yard.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "СԺ"); 
        set("long", @LONG
����һ�����������СԺ��һ��˥�ϵİ������Ѿ���ʼ��ή��һ
���ƹ������ǽ�ǣ�ǽ��һ���п�ˮ����Ժ�и���������ʯ�ʣ�һ��
���ߴ������ڵ����૵ز�֪��˵Щʲô��Ժ�����׾���������С
�ݣ���ľ�ſ��ţ��紵֮�£����¸¡����졣
LONG); 
        set("exits",([
        "west":__DIR__"nongjia",
        "south":__DIR__"stoneroad",
        "north":__DIR__"neishi",
        ]) );
        set("objects", ([
                __DIR__"npc/oldyu": 1,
        ]) );
        set("indoors", "libie");
        set("coor/x",45);
        set("coor/y",210);
        set("coor/z",0);
        setup(); 
} 
int valid_leave(object me, string dir)
{       object room; 
        room=this_object();
        
        if(!present("old yu",room)&&dir!="north")
        if(me->query_temp("libie/���_ȡ��")&&!me->query_temp("libie/���_����"))
                return notify_fail(HIY"�����Ͽ�ȥȡ�ţ�\n"NOR);         
        return 1; 
}  
