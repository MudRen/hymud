//lianglu3.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
һ��̹���Ļ����ٵ���������,·���˼��Ѿ�����ϡ��.
ż����һ���ӿ��������������������,�����Ƿ糾���͵�����,��Ȼ
�߹�һ����������������;.
LONG
         );
        set("exits", ([ 
                "east"          :       __DIR__ "lianglu2",            
                "northwest"     :       __DIR__ "lianglu4",
                ])
        );
//      replace_program(ROOM);
        setup();
}

