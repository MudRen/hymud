//road23.c.��ƽ��
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"��ƽ��"NOR);
    set("long",@LONG
�����Ǿ�ƽ������Χ�����ƽ��סլ����һЩ����. ����ϸ����ΰ�������
���ӽ����������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ�����ľ������
���٣���˵�⸽����������һƷ���ܶ����ڣ��������س�����˶��Եú����أ�
ƽʱһ��İ��ն������������
LONG);
   
    set("exits",([
         "north"   : __DIR__"road24",
         "south"   : __DIR__"road11",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}

