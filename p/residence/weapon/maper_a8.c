#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[1;33m°ÔÍõÖ®Ö¤[2;37;0m", ({ "taibai waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[1;37m
		ÕÔ¿ÍçÏºúÓ§  Îâ¹³ËªÑ©Ã÷		Òø°°ÕÕ°×Âí  ìªí³ÈçÁ÷ĞÇ
		Ê®²½É±Ò»ÈË  Ç§Àï²»ÁôĞĞ		ÊÂÁË·÷ÒÂÈ¥  Éî²ØÉíÓëÃû
		ÏĞ¹ıĞÅÁêÒû  ÍÑ½£Ï¥Ç°ºá		½«ÖË¡õÖìº¥  ³ÖõüÈ°ºîÙø
		Èı±­ÍÂÈ»Åµ  ÎåÓüµ¹ÎªÇá		ÑÛ»¨¶úÈÈáá  ÒâÆøËØÄŞÉú
		¾ÈÕÔ»Ó½ğé³  ºªµ¦ÏÈÕğ¾ª		Ç§Çï¶ş×³Ê¿  ĞúºÕ´óÁº³Ç
		×İËÀÏÀ¹ÇÏã  ²»²ÑÊÀÉÏÓ¢		Ë­ÄÜÊé¸óÏÂ  °×Ê×Ì«Ğş¾­
[2;37;0mÕâÊÇÒ»ÌõÓÉ¾ø¶Ô¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁù½ïÈıÁ½¾ÅÇ®µÄ[1;37mÌ«°×Ö®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [31m»ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [33mÍÁ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;35m·ç[2;37;0m:[35m±ê×¼[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[35m±ê×¼[2;37;0m ÖÜÌì:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m ²»ÀÏ:[35m±ê×¼[2;37;0m ÍşÁ¦:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mµØÍ¼Ò»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m×¦·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "µØÍ¼Ò»ºÅ");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 59);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 400);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 74);
    set("armor_prop/qi", 65);
    set("armor_prop/jing", 50);
    set("armor_prop/jingli", 50);
    set("armor_prop/damage", 301);

    set("wtypeA",7);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",13);
    set("wtypeE",14);
    set("wtypeF",5);
    set("wtypeG",12);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",6);
    set("wtypeK",5);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";