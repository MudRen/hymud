#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[34m����֮��[2;37;0m", ({ "zhanlu shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31mտ¬��������������Ӳ���ھ���������ǧ�������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ��ؾŽ����һǮ��[31mտ¬֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȼ�̣�����[35m�������[2;37;0m�ķ�������
������˼����ŷ��ţ�
[40m��[2;37;0m:[1;32mħ��[2;37;0m [1;36m��[2;37;0m:[1;33m��ʥ[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[1;33m��ʥ[2;37;0m 
[1;37m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[1;36m����[2;37;0m 
��ʯ:[1;32mħ��[2;37;0m ����:[1;32mħ��[2;37;0m 
����:[1;36m����[2;37;0m ����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�ɶ�[2;37;0m ������һЩ�� [1;32mצ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "�ɶ�");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",37);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 94);
    set("armor_prop/attack", 91);


    set("armor_prop/armor", 876);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 71);
    set("armor_prop/qi", 52);
    set("armor_prop/jing", 59);
    set("armor_prop/jingli", 59);
    set("armor_prop/damage", 93);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",13);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",10);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";