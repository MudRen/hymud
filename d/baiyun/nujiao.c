 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "ŭ��");
        set("long", @LONG 
���������Ƶ��У�Ψ��ŭ����Ȼ������ֵˮ��֮�ʣ����˳�����Χ�Ľ�ʯ����ס
����ʹ���Ĳ��񵴣�������죬������һ�̷Ż����������ﳤ���ܿ���ʴ����ˮ��
ˢ�����Ҷ��ͣ�ʯɫ����Ľ�ʯΡȻ����������ŭ����ͷ������������������������
����ãã��ŭ�˾����в�ʱ�м�ֻ�����貫����ŭ�ˣ���ϼ�����졢�󺣡�ŸӰ��
�·������������֮�䣬������Ȼ���¡�
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"shiliang",
            ])); 
        set("objects",  
           ([  
       __DIR__"obj/rock" : 1,
       __DIR__"npc/baiyunxian" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",80); 
        set("coor/y",-1710); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}       
