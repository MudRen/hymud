// room: xing7.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "�ƺ��ذ�");
        set("long", @LONG
�����������츮������--������, ����¥��, ȫ����װ������ʿ��������
������Ѳ����. ��Ϊ������Ԫ�����Ϊǿ��֮��, �������ľ�����֯����, ս��
���ǳ�ǿ���Ĳ���. ���ű�վ��һ������ս��, �����������ı���, ���Ǿ���
��ע����ÿһ������������. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing6",
                "northeast"     :       __DIR__ "door4",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


