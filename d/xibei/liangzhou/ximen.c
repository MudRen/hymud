//ximen.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����ʺ����ݵ�����,�����������ĵ�Ͻ��,��¥��Ʈ������ɫ�Ľ���
���������޴�ͭ���ĳ��Ž�����,ֻ������Ľ��������˺ͳ���ͨ��.���
ȫ����װ�ı����ڳ�������Ѳ��, ÿһ�����ɵĹ������˶��ᱻ�����̲�
һ��.���������ǽ�����ż���׽�ü�������.
LONG
        );
set("outdoors","liangzhou");
        set("exits", ([ 
               "west"           :       "/d/xibei/silk1",

                "east"          :       __DIR__ "lroad5",
                ]) );

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ])); 
        
//      replace_program(ROOM);
        setup();
}

