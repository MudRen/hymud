
//Writen by lnwm on 97/07/09

//shenren.c

//����»�������
//����������ܳ��ĵ��ӣ�������ɽ����ϵ�����»����Ľ���
//�����԰Σ�׷��ң�Ӷ�ȥ������ң��׷����ˮ��һֱ׷���Ĵ���
//��ң�Ӹ����ϣ�ָ���������У����������ڴˣ��յ���ң�ӡ�

//�н��

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��������", ({ "baiyi laoren","laoren","ren" }) );
    set("gender", "����" );
    set("age", 40);
    set("title","");
	set("long",
"һλ�������\n"
	    );
    setup();
}




