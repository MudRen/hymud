//yuan2.c.����Ժ
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"����Ժ"NOR);
    set("long",@LONG
����ר������������װ���;������ʵĹٸ��ֹ�ҵ������ֱ��Ϊ���ӷ���
����ƽ�����ҵ�Ҳ�ܻ�Ծ��������Ժ��ר���ƹ������ڣ����ݳ峵������ս
���ȡ�����һ������ǰ�����ر����֣�һ�Ӷ�ʿ���ڼ��޺����þ�е��ƽʱ��һ
����Ҳû�С�
LONG);
   
    set("exits",([
        "east"    : __DIR__"road3",
    ]));
     set("objects", ([
          __DIR__"npc/guan2" : 1,
    ]) );
    setup();
}

