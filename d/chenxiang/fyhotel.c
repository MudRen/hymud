#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���ƿ�ջ"); 
        set("long", @LONG
��־�ͷ��ͭ�Ž��գ�һ�����ɸߵ�����ϣ���������յ����ĵ����� 
���ĵ�������ڵ��֣� 
                   ��  ��  ��  ջ     
LONG);
        set("type","house"); 
        set("exits",([
                "south":__DIR__"fyavenue",
                "north":__DIR__"fyhall",
        ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-480);
        set("coor/y",-460);
        set("coor/z",0);
                    
        set("objects",([
                __DIR__"npc/miao":1,
                __DIR__"npc/zhao":1,
                __DIR__"npc/zhang":1,
        ]) );
        setup();
} 
int valid_leave(object me, string dir)
{
        if( userp(me) && dir=="north")
        {
                if(!me->query_temp("marks/longlife_peacockmap"))
                {
                        if(present("miao shaotian", this_object()))
                        {
                    return notify_fail("�����������Ц������Ĳ��ͷ�������������\n");
                        }
                        else if(present("zhao yidao", this_object()))
                        {
                    return notify_fail("��һ������һ�����ȵ���С������û�»ؼҳ���ȥ����������¡�\n");   
                   }
                        else if(present("zhang san", this_object()))
                        {
                    return notify_fail("�����ٺ�Ц����С���������ȥ�ˣ�үү����ô�졣\n"); 
                        }
                }
                else
                {
                        message_vision(HIY"$Nһè��͵͵������ƿ�ջ��\n\n"NOR,me);
                        return 1;
                }
        }
        return 1;
}      
