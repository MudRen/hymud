//lianglu6.c

inherit ROOM;

void create()
{
        set("short", "ɳ��·");
        set("long", @LONG
�����ں������ȿ�������ϣ������������ݣ��Թź������ʺ����ұ���֮�ء�
���������ܿ�������ɽΡ���Ⱥɽ,ɽ��ӳ��ε��������£���е��ػ�Ϊ֮һ��
��Ȼ���ﱻ��Ϊ���ȣ���ʵ������һƬ�ǳ�������ƽԭ������ɽѩ��Ļ�ѩ�ڻ���
������Ƭ���أ������������������
LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "lianglu5",            
                "northwest"     :       __DIR__ "lianglu7",
                ])
        );
//      replace_program(ROOM);
        setup();
}

