//lianglu4.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
һ��̹���Ļ����ٵ�,������һֱ��ȥ,����ƽԭ,����������������.
�������ƽ���.ƽԭ�ѽ�����ɳʯ������.����λ�������������м�.
�����ѿ�ԶԶ��������ɽ�����ɽ��,����������,��ͽ������������.
LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "lianglu3",            
                "northwest"     :       __DIR__ "wuqiao",
                ])
        );
//      replace_program(ROOM);
        setup();
}

