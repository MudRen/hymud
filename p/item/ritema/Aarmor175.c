#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;37mË«ÐÇÖ®Åû·ç[2;37;0m", ({ "general armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
		set("long", @LONG
Ë«ÐÇÖ®Åû·ç[2;37;0mÕâÊÇÒ»¼þÓÉ¼«Îª¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[33mÑÇÂé[2;37;0mÖÆ³É£¬ÖØÒ»½ïÈýÁ½¾ÅÇ®µÄ[1;37mË«ÐÇÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆðÀ´¼«Îª¼á¹Ì£¬¾ßÓÐ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[33mºÜ¸ß[2;37;0m ¸£Ô´:[33mÒ»°ã[2;37;0m 
ÌìÔ¨:[33mÒ»°ã[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
³¤Éú:[33mÒ»°ã[2;37;0m ÍþÁ¦:[36m²»´í[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",6);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",7);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 27);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 7);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 17);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";