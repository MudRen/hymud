//lroad5.c

inherit ROOM;

void create()
{
        set("short","ɳ��·");
        set("long", @LONG
���ݳǵ����ĵ�·�����������ݵ����ţ���˵�����Ǵ�ǣ�������·
�沢��ƽ���������߹����������������ˣ�����Щ�������������
�������ˣ����������ζ�����ǿ����Ҹ��ط�����һ��ƣ�������ģ�����
���������Ļ�ɳ��һ���޼ʵĻ�Ұ��
������һ���ӹ�¥���ϱ���һ�Ҳ�ׯ�������������ݳǵ����ɵ���������
ͨ�������ġ�
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "east"          :       __DIR__ "lroad4",
                "west"          :       __DIR__ "ximen",
                "south"         :       __DIR__ "chadian",
                "north"         :       __DIR__ "zhonglou",
                ])
        );
//      replace_program(ROOM);
        setup();
}

