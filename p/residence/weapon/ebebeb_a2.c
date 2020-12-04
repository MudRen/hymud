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
	      set_name("[1;37m���͵�˫��[2;37;0m", ({ "lanhong hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[36m����֮����[2;37;0m����һ����ʮ�ּ�Ӳ��[1;37m����[2;37;0m����[1;33mľ�޻�[2;37;0m�Ƴɣ�����������һǮ��[36m����֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m ������ʮ�ּ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;31m��˫[2;37;0m 
[1;37m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ����:[35m��׼[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m 
����:[35m��׼[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĽ����[2;37;0m ������һЩ�� [1;32m�Ʒ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ľ����");
		set("value", 16000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",16);
		set("armor_prop/karey",8);
		set("armor_prop/percao",8);
		set("armor_prop/dexerity",16);
		set("armor_prop/constitution",24);
    set("armor_prop/dodge", 44);
    set("armor_prop/parry", 33);
    set("armor_prop/attack", 23);


    set("armor_prop/armor", 252);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 8);
    set("armor_prop/qi", 50);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 767);

    set("wtypeA",8);
    set("wtypeB",1);
    set("wtypeC",9);
    set("wtypeD",3);
    set("wtypeE",1);
    set("wtypeF",12);
    set("wtypeG",9);
    set("wtypeH",1);
    set("wtypeI",4);
    set("wtypeJ",2);
    set("wtypeK",2);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";