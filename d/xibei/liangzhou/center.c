//center.c

inherit ROOM;

void create()
{
        set("short","���ļ���");
        set("long", @LONG
��������,���ַǷ������Ĺ㳡.��˵�����ս������˿��֮·��˳
����ͨ,�����������ó�״�δֹͣ��.����������ԭ��С��������������
�еĳ����, �㻹�ܿ�������������Ǹ�Ŀ��������˲��Ű����������
������С�����ּۻ���. �ϱ���һ������,����ͨ�����ݳǵĳ���,����һ
��ֱ·ͨ��һ����Ժ.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "north"         :       __DIR__ "lroad3",
                "south"         :       __DIR__ "dangpu",
                "west"          :       __DIR__ "lroad4",
                "east"          :       __DIR__ "lroad2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

