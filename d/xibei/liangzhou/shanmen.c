//shanmen.c

inherit ROOM;

void create()
{
        set("short","������ɽ��");
        set("long", @LONG
������������Ժ,�ഫΪ�����ɮ�Ħ��ʲ��������֮��.��Ժ������
������,ɽ�������޵���������,���ܶ���,������� .��������һ�����
, ����ī��д"������"��������.����ɽǽ��д��һ���޴��"��"��.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "lroad3",
                "north"         :       __DIR__ "tingyuan",
                ])
        );
//      replace_program(ROOM);
        setup();
}

