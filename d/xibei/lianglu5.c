//lianglu5.c

inherit ROOM;

void create()
{
        set("short", "ɳ��·");
        set("long", @LONG
���Ѿ����������ĺ������ȣ���Խ�����������ͨ�����ݵĹٵ����㽫������ԭ
���������ܿ�������ɽΡ���Ⱥɽ,ɽ��ӳ��ε��������£���е��ػ�Ϊ֮һ����Ȼ
���ﱻ��Ϊ���ȣ���ʵ������һƬ�ǳ�������ƽԭ������ɽѩ��Ļ�ѩ�ڻ���������Ƭ
���أ������������������
LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "wuqiao",            
                "northwest"     :       __DIR__ "lianglu6",
                ])
        );
//      replace_program(ROOM);
        setup();
}

