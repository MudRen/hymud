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
                "north":__DIR__"hyuan",
                "west":__DIR__"shulin4",
                "east":__DIR__"shulin3",
                "south":__DIR__"qiao",
        ]) );
        set("objects", ([
      
                __DIR__"npc/langzhong" : 1,
                        __DIR__"npc/xiaofan2" : 1,
                        ]) );
       set("outdoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-340);
        set("coor/z",100);
        setup();
} 