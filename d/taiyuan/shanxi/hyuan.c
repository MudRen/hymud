#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�ɻ�԰"); 
        set("long", @long
Ժ�������˸�ɫ����ľջ����ƾ��ж�ʤ������ҩ������֪��
�׾������°ס�һ��ѩ���������¡��Ͼ���˫���ࡢ�����������
�̡���������˺졢���������ܽ�ء�����Ժ���м�����ɫ�ر�
�޵Ļƻ�������Ƶ������һ������������Ӻ���ɻ����Ǿ��Ǵ�
���ô����Ľ�Ѯ����
long); 
       // set("type","waterbody");
        set("exits",([
                "northeast":__DIR__"fang3",
                "northwest":__DIR__"fang4",
                "east":__DIR__"fang1",
                "west":__DIR__"fang2",
                "north":__DIR__"tang",
                "south":__DIR__"yuan4",
        ]) );
                set("objects", ([
      
        __DIR__"npc/begger" : 1,
               
                                        __DIR__"npc/zhanggui" : 1,
                        ]) );
       set("outdoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-330);
        set("coor/z",100);
        setup();
} 