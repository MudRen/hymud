//yizhan2.c

inherit ROOM;

void create()
{
        set("short","��վ");
        set("long", @LONG
���ݳǵ���ݣ��������Ĺٲ���Ϣ��⣬Ժ�䲻��ֻ��СС�ļ���
�᷿,��ȴ��������ʮ�ַ�æ��������һ�����.  ���˵������ݳ���Ҫ��
����·�����Ҫ��һ������, ������ʢ������֮��, �����ﻻ�ϵ������
����ˡ�
LONG
        );
        set("exits", ([ 
                "north"         :       __DIR__ "lroad1",
                ])
        );
//      replace_program(ROOM);
        setup();
}

