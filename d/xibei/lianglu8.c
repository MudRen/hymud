//lianglu8.c

inherit ROOM;

void create()
{
        set("short", "ɳ��·");
        set("long", @LONG
���������ݳǣ���¥�ߴ�Ρ�룬����������������Ѳ�ߣ�����ʱ����һ�³��¹���
�Ŀ��̺����ˡ����ſ��м���Уξ�����ע����ÿһ����·���ˣ����űߵĳ�ǽ����
�ż���׽�ü����ܦ�ģ���Ȼ�����﷢���˲�Ѱ�����¼�.
LONG
        );
        set("exits", ([ 
                "east"          :       __DIR__ "lianglu7",            
             "west"     :       __DIR__"liangzhou/dongmen",
                ])
        );
//      replace_program(ROOM);
        setup();
}

