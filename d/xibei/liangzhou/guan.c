//guan.c

inherit ROOM;

void create()
{
        set("short", "���ݳǹ�");
        set("long", @LONG
վ�����ݸߴ�ĳ���¥֮��,����Զ��,����Ƶ�, �㲻���е��ػ�һ
����.������,�Ǻ�������һ���޼���ƽԭ,һ����·��ֱ������ȥ,��
��,�ɼ�����������,���Ѷ�ȥ,�����Ա����������ߵĸ��, ����,����
Ȼ��������ɽ����Ⱥ��.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "down"          :       __DIR__ "dongmen",            
                "north"         :       __DIR__ "madao1",
                "south"         :       __DIR__ "madao2",
                ])
        );

        set("objects", ([

                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                ]) );
//      replace_program(ROOM);
        setup();
}

