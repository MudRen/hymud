// xiaoxi1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "ɽ��СϪ");
        set("long", @LONG
����һ��ɽ��СϪ���Ա߳����˲�֪����Ұ��Ұ�ݣ���Χ�������ˣ�ֻ
��С����ˮ���������졣һЩ�ڿʵĶ�����Ϫ�ߺ�ˮ��Զ��ż��������Ů��
�ֵ���Ц�����㲻���е����ƣ�����ĵض��ĵط����������Ļ�Ц���أ���
������̽��Դͷ���ҳ�������
LONG
        );
        
	set("outdoors", "houjizhen");
	set("resource/water", 1);

        set("exits", ([           
                "eastdown" : __DIR__"xiaoxi",
		"westup" : __DIR__"pubu",
        ]));


        setup();
	replace_program(ROOM);
}
