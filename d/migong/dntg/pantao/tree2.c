#include <ansi.h>
inherit __DIR__"tree.c";

void falldown(object,object);
void create()
{
        set("short", "�������"NOR);
        set("long", "��Χ֦Ҷ��ï��������գ�һƬ�������������������ź�
ͮͮ������������֡��������Ҳ㻨��ʵ����ǧ��һ�졣\n");




        set("magicroom",1);set("exits", ([
  "down": __DIR__"pan2b",
        ]));

        set("objects", ([
               __DIR__"obj/pantao2": 2,
              ]));

        setup();
}


