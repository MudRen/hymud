//madao2.c

inherit ROOM;

void create()
{
        set("short","���");
        set("long", @LONG
��¥���½�ͨ���õ����,���Һܿ�,�ú���שʯ����, бб��ͨ��
����.��Ϊս�һ�û�н���, һ��һ�ӵ�����ʿ�����ϳ������ص�Ѳ��,��
�Ǹ�������������������Ǻ���¹Ƥѥ�����������Ƥ�£����ǵ�װ
���Ѿ�����ԭ��ʿ����Ȼ��ͬ.
LONG

        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "cheng2",            
                "north"         :       __DIR__ "guan",
                ])
        );
//      replace_program(ROOM);
        setup();
}

