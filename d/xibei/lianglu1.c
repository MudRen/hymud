//lianglu1.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
һ��̹���Ļ����ٵ���������,��������ͽ��뿪��ԭ,��������.
���߾��������������ݿ�������¥,������һƬ��ã��ƽԭ,�����ֱ������.
��ʱ�м�ƥ���������߼��۶���,���ϵĹٲ�ߺ����,��Ȼ�н����Ĺ���.

LONG
        );
        set("exits", ([ 
                "east"          :        __DIR__"huangye2",            
                "west"          :       __DIR__ "lianglu2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

