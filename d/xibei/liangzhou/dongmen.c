//dongmen.c

inherit ROOM;

void create()
{
        set("short", "���ݶ���");
        set("long", @LONG
�����ʺ����ݵĶ���,�����������ĵ�Ͻ��,��¥��Ʈ������ɫ�Ľ���
���������޴�ͭ���ĳ��Ž�����,ֻ������Ľ��������˺ͳ���ͨ��.���
ȫ����װ�ı����ڳ�������Ѳ��, ÿһ�����ɵĹ������˶��ᱻ�����̲�
һ��.���������ǽ�����ż���׽�ü�������.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
             "east"     :       "/d/xibei/lianglu8",
                "up"            :       __DIR__ "guan",
                "west"          :       __DIR__ "lroad1",
                ])
        );
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));        
//      replace_program(ROOM);
        setup();
}

