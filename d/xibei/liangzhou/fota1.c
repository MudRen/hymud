//fota1.c

inherit ROOM;

void create()
{
        set("short","����");
        set("long", @LONG
����һ����������ȴ��Ρ��ׯ�ϵķ������ǵ�������˿��֮·����
��ԭʱ���ޣ����ְ��棬��ʮ���㡣ÿ�㶼��������ֽ���񣬸���üĿ
���飬ÿ�����ܵİ˸����϶�׺�з��壬΢�������������������������
��ֱ��������
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "north"         :       __DIR__ "lroad2",               
                "up"            :       __DIR__ "fota2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

