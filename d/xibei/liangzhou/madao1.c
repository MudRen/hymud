//madao1.c

inherit ROOM;

void create()
{
        set("short","���");
        set("long", @LONG
��¥���½�ͨ���õ����,���Һܿ�, �ú���שʯ����,бб��ͨ��
����.��Ϊս�һ�û�н���, һ��һ�ӵ�����ʿ�����ϳ������ص�Ѳ��,��
�Ǹ�������������������Ǻ���¹Ƥѥ�����������Ƥ�£����ǵ�װ
���Ѿ�����ԭ��ʿ����Ȼ��ͬ.
LONG

        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "guan",            
                "north"         :       __DIR__ "cheng1",
                ])
        );
//      replace_program(ROOM);
        setup();
}

