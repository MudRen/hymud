#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;33m����[2;37;0m", ({ "xuanyuan hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;35m���ջƵ۳ִ�������ָ�ϳ��ϣ�������ɨ��������Ӧ�����ɣ������޶�ս��ȣ�
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[1;35m��ԯ֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;33m��ʥ[2;37;0m [36mľ[2;37;0m:[1;35m����[2;37;0m [31m��[2;37;0m:[1;31m��Ԫ[2;37;0m [1;35m��[2;37;0m:[1;31m��Ԫ[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ��Ԩ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����С[2;37;0m ������һЩ�� [1;32m�ȷ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "����С");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",35);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 45);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 491);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 61);
    set("armor_prop/jingli", 61);
    set("armor_prop/damage", 973);

    set("wtypeA",10);
    set("wtypeB",11);
    set("wtypeC",0);
    set("wtypeD",13);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";