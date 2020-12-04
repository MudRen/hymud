#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[34m°ÙºÏÖ®·þ×°[2;37;0m", ({ "general cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
		set("long", @LONG
°ÙºÏÖ®·þ×°[2;37;0mÕâÊÇÒ»¼þÓÉ·Ç³£¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[33mÑÇÂé[2;37;0mÖÆ³É£¬ÖØÈý½ïÒ»Á½¾ÅÇ®µÄ[34m°ÙºÏÖ®·þ×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆðÀ´·Ç³£¼á¹Ì£¬¾ßÓÐ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;37mÀ×[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[33mºÜ¸ß[2;37;0m ÌìÔ¨:[32m¼«²î[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
ÌåÁé:[36m²»´í[2;37;0m °×Ê¯:[32m¼«²î[2;37;0m ²»ÀÏ:[33mÒ»°ã[2;37;0m 

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
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",2);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 3);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 180);
    set("armor_prop/defense", 15);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 9);
    set("armor_prop/jingli", 9);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "leg",
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