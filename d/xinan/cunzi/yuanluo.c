//writen by lnwm
//yuanluo.c

inherit ROOM;

void create()
{
    set("short", "ũ��Ժ��");
    set("long", @LONG
�ɸɾ�����ũ��СԺ��������Ů����һ���ڿ��ܸɣ�����Ժ�䶼����
ˮ��û��һƬ��Ҷ����������һ���Լ��Ĳ�԰��������һ������������
���ű߹���һ�������ĸ����������߾�����ҵ����ݡ�������שʯ��
�ɣ���Ȼ����һ�ұȽϸ�ԣ��ũ����
LONG
        );
    set("exits", ([ 
                "east"      :       __DIR__ "caiyuan",
        "south"     :       __DIR__ "chaimen",
        "north"     :       __DIR__ "tangwu",
        "west"      :       __DIR__ "chufang",
        ]));
    
    set("outdoors","lnwm");
    setup();
}



